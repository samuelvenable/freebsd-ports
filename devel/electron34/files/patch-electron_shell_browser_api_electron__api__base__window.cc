--- electron/shell/browser/api/electron_api_base_window.cc.orig	2025-05-01 14:56:40 UTC
+++ electron/shell/browser/api/electron_api_base_window.cc
@@ -41,7 +41,7 @@
 #include "shell/browser/ui/views/win_frame_view.h"
 #include "shell/browser/ui/win/taskbar_host.h"
 #include "ui/base/win/shell.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/ui/views/opaque_frame_view.h"
 #endif
 
@@ -986,7 +986,7 @@ void BaseWindow::SetIconImpl(v8::Isolate* isolate,
   static_cast<NativeWindowViews*>(window_.get())
       ->SetIcon(native_image->GetHICON(GetSystemMetrics(SM_CXSMICON)),
                 native_image->GetHICON(GetSystemMetrics(SM_CXICON)));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static_cast<NativeWindowViews*>(window_.get())
       ->SetIcon(native_image->image().AsImageSkia());
 #endif
@@ -1043,7 +1043,7 @@ void BaseWindow::SetAppDetails(const gin_helper::Dicti
 }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BaseWindow::SetTitleBarOverlay(const gin_helper::Dictionary& options,
                                     gin_helper::Arguments* args) {
   // Ensure WCO is already enabled on this window
@@ -1296,7 +1296,7 @@ void BaseWindow::BuildPrototype(v8::Isolate* isolate,
       .SetMethod("setThumbnailToolTip", &BaseWindow::SetThumbnailToolTip)
       .SetMethod("setAppDetails", &BaseWindow::SetAppDetails)
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       .SetMethod("setTitleBarOverlay", &BaseWindow::SetTitleBarOverlay)
 #endif
       .SetProperty("id", &BaseWindow::GetID);
