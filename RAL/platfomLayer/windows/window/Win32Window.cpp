/////////////////////////////////////////////////////////
// Copyright (C) 2023                                  //
// Ondřej Nedojedlý (https://www.github.com/ondranedo),//
// Matyáš Noska (https://www.github.com/sutiama),      //
// Vojtěch Šokala (https://github.com/Karnatour),      //
// Adam Wiszczor (https://github.com/1nome).           //
//                                                     //
// This file is part of `RAL_PROJECT` project          //
// which is released under `GNU General Public         //
// License v3.0` license.                              //
// See file `LICENSE` for full license details.        //
/////////////////////////////////////////////////////////

#ifdef RAL_WINDOWS

#include "Win32Window.h"

#include <core/utility/Asserts.h>
#include <core/events/eventTypes/WindowEvents.h>
#include <core/events/eventTypes/MouseEvents.h>
#include <core/events/eventTypes/KeyEvents.h>
#include <vendor/glad/include/glad/glad.h>

typedef void (APIENTRY *PFNGLFUNCTION)(void);

PFNGLFUNCTION GetGLFunction(const char* name) {
    HMODULE module = GetModuleHandle("opengl32.dll");
    if (module) {
        return reinterpret_cast<PFNGLFUNCTION>(GetProcAddress(module, name));
    }
    return nullptr;
}


LRESULT CALLBACK RAL::Win32::Win32Window::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            PIXELFORMATDESCRIPTOR pfd = {
                    sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd
                    1,                     // version number
                    PFD_DRAW_TO_WINDOW |   // support window
                    PFD_SUPPORT_OPENGL |   // support OpenGL
                    PFD_DOUBLEBUFFER,      // double buffered
                    PFD_TYPE_RGBA,         // RGBA type
                    24,                    // 24-bit color depth
                    0, 0, 0, 0, 0, 0,      // color bits ignored
                    0,                     // no alpha buffer
                    0,                     // shift bit ignored
                    0,                     // no accumulation buffer
                    0, 0, 0, 0,            // accum bits ignored
                    32,                    // 32-bit z-buffer
                    0,                     // no stencil buffer
                    0,                     // no auxiliary buffer
                    PFD_MAIN_PLANE,        // main layer
                    0,                     // reserved
                    0, 0, 0                // layer masks ignored
            };
            Win32Window::m_hDc = GetDC(Win32Window::m_hWnd);
            iPixelFormat = ChoosePixelFormat(m_hDc, &pfd);
            break;
        }
        case WM_CLOSE:
            DestroyWindow(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_KEYDOWN: {
            if (wParam == 0x4A) {
                RAL_LOG_FATAL("J pressed\n");
            }
        }
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

namespace RAL::Win32 {
    Win32Window::Win32Window() : Window(WindowSpec()), m_window(nullptr), m_hInstance(GetModuleHandle(nullptr)) {}

    void Win32Window::init() {
        RAL_LOG_DEBUG("Win32Window initialized");

        const char* CLASS_NAME = "Window Class";

        WNDCLASS wndClass = {};
        wndClass.lpszClassName = CLASS_NAME;
        wndClass.hInstance = m_hInstance;
        wndClass.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
        wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wndClass.lpfnWndProc =  DefWindowProc;

        RegisterClass(&wndClass);

        DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

        int width = 640;
        int height =480;

        RECT rect;
        rect.left = 250;
        rect.top = 250;
        rect.right = rect.left + width;
        rect.bottom = rect.top + height;

        AdjustWindowRect(&rect, style, false);

        m_hWnd = CreateWindowEx(
                0,
                CLASS_NAME,
                "Title",
                style,
                rect.left,
                rect.top,
                rect.right - rect.left,
                rect.bottom - rect.top,
                nullptr,
                nullptr,
                m_hInstance,
                nullptr
        );
        SetWindowLong(m_hWnd, GWL_STYLE,GetWindowLong(m_hWnd, GWL_STYLE) | WS_MINIMIZEBOX);
        SetWindowLong(m_hWnd, GWL_STYLE,GetWindowLong(m_hWnd, GWL_STYLE) | WS_MAXIMIZEBOX);
        ShowWindow(m_hWnd, SW_SHOW);
    }

    void Win32Window::release() {
        RAL_LOG_DEBUG("Win32Window released");
    }

    void Win32Window::update() {
        RAL_ASSERT(m_window, "Cannot update window, window `%s` is not created", m_spec.m_title);
        if(!m_window) return;
        MSG msg = {};

        while(PeekMessage(&msg, nullptr, 0u,0u, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void Win32Window::makeContextCurrent() {
        RAL_ASSERT(m_window, "Cannot make context current, window `%s` is not created", m_spec.m_title);
        if(!m_window) return;
        wglMakeCurrent(m_hDc, m_rc);
        gladLoadGL();
        glViewport(0,0, 640, 480);
    }

    void Win32Window::setDims(uint16_t width, uint16_t height) {
        RAL_ASSERT(m_window, "Cannot set window dimensions, window `%s` is not created", m_spec.m_title);
        if(!m_window) return;
    }

    void Win32Window::setTitle(const std::string &title) {
        RAL_ASSERT(title.size() > 0, "Window `%s` title cannot be empty", m_spec.m_title);
        RAL_ASSERT(title.size() < RAL_WINDOW_SPEC_TITLE_SIZE, "Window `%s` title cannot be longer than %d characters", m_spec.m_title, RAL_WINDOW_SPEC_TITLE_SIZE);
        //TODO glfwSetWindowTitle(m_window, title.c_str());
        strcpy(m_spec.m_title,title.c_str());
    }

    void Win32Window::setVSync(bool state) {
        //TODO global::glfw.setVSync(state);
    }

    void Win32Window::create() {
        m_window = new Win32Window();
        if(m_window)
        {
            RAL_LOG_DEBUG("Windows window `%s` created", m_spec.m_title);
            m_spec.m_created = true;
            return;
        }
        RAL_LOG_DEBUG("Windows window  creation failed");
    }

    void Win32Window::destroy() {
        RAL_LOG_DEBUG("Windows window `%s` destroyed", m_spec.m_title);
        const char* CLASS_NAME = "Window Class";
        UnregisterClass(CLASS_NAME, m_hInstance);
        m_spec.m_created = false;
    }

    void Win32Window::setCallbacks() {}
    void Win32Window::swapBuffers()
    {
        m_hDc = GetDC(m_hWnd);
        RAL_ASSERT(m_window, "Cannot call swapBuffers, window `%s` is not created", m_spec.m_title);
        SwapBuffers(m_hDc);
    }

    bool Win32Window::getVSync() const {
        return false;
    }
} // RAL

#endif //!RAL_WINDOWS