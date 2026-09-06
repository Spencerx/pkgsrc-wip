$NetBSD$

Treat NetBSD the same as Linux.

--- src/binary/module_base.cpp.orig	2026-09-06 08:40:24.216792524 +0000
+++ src/binary/module_base.cpp
@@ -7,7 +7,7 @@
 #include <mutex>
 #include <unordered_map>
 
-#if IS_LINUX || IS_APPLE
+#if IS_LINUX || IS_NETBSD || IS_APPLE
  #include <unistd.h>
  #include <dlfcn.h>
  #if IS_APPLE
@@ -21,7 +21,7 @@
 
 CPPTRACE_BEGIN_NAMESPACE
 namespace detail {
-    #if IS_LINUX
+    #if IS_LINUX || IS_NETBSD
     Result<std::uintptr_t, internal_error> get_module_image_base(const std::string& object_path) {
         static std::mutex mutex;
         std::lock_guard<std::mutex> lock(mutex);
