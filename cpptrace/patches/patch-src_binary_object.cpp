$NetBSD$

Treat NetBSD the same as Linux.

--- src/binary/object.cpp.orig	2026-09-06 09:09:56.442014907 +0000
+++ src/binary/object.cpp
@@ -11,7 +11,7 @@
 #include <mutex>
 #include <unordered_map>
 
-#if IS_LINUX || IS_APPLE
+#if IS_LINUX || IS_NETBSD || IS_APPLE
  #include <unistd.h>
  #include <dlfcn.h>
  #if IS_LINUX
@@ -26,7 +26,7 @@
 
 CPPTRACE_BEGIN_NAMESPACE
 namespace detail {
-    #if IS_LINUX || IS_APPLE
+    #if IS_LINUX || IS_NETBSD || IS_APPLE
     #if defined(CPPTRACE_HAS_DL_FIND_OBJECT) || defined(CPPTRACE_HAS_DLADDR1)
     std::string resolve_l_name(const char* l_name) {
         if(l_name != nullptr && l_name[0] != 0) {
