// Copyright (c) 2015 Klaralvdalens Datakonsult AB (KDAB).
// All rights reserved. Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef CEF_TESTS_PHANTOMJS_APP_H_
#define CEF_TESTS_PHANTOMJS_APP_H_

#include "include/cef_app.h"
#include "include/wrapper/cef_message_router.h"

class PrintHandler;

class PhantomJSApp : public CefApp,
                     public CefBrowserProcessHandler,
                     public CefRenderProcessHandler
{
 public:
  PhantomJSApp(bool dis, unsigned long width, unsigned long height);
  ~PhantomJSApp();

  // CefApp methods:
  virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override
  {
    return this;
  }

  virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override
  {
    return this;
  }
  void OnRegisterCustomSchemes(CefRefPtr<CefSchemeRegistrar> registrar) override;

  // CefBrowserProcessHandler methods:
  virtual void OnContextInitialized() override;
  virtual CefRefPtr<CefPrintHandler> GetPrintHandler() override;

  // CefRenderProcessHandler methods:
  void OnWebKitInitialized() override;
  void OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                        CefRefPtr<CefV8Context> context) override;
  void OnContextReleased(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                         CefRefPtr<CefV8Context> context) override;
  bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process,
                                CefRefPtr<CefProcessMessage> message) override;

 private:
  CefRefPtr<PrintHandler> m_printHandler;
  CefRefPtr<CefMessageRouterRendererSide> m_messageRouter;
  // Include the default reference counting implementation.
  IMPLEMENT_REFCOUNTING(PhantomJSApp);
  bool disableOnScreenmode;
  unsigned long width;
  unsigned long height;
};

#endif  // CEF_TESTS_PHANTOMJS_APP_H_
