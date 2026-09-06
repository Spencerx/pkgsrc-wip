$NetBSD$

Add platform support for NetBSD.

--- src/platform/platform.hpp.orig	2025-07-25 05:41:51.000000000 +0000
+++ src/platform/platform.hpp
@@ -4,6 +4,7 @@
 #define IS_WINDOWS 0
 #define IS_LINUX 0
 #define IS_APPLE 0
+#define IS_NETBSD 0
 
 #if defined(_WIN32)
  #undef IS_WINDOWS
@@ -14,6 +15,9 @@
 #elif defined(__APPLE__)
  #undef IS_APPLE
  #define IS_APPLE 1
+#elif defined(__NetBSD__)
+ #undef IS_NETBSD
+ #define IS_NETBSD 1
 #else
  #error "Unexpected platform"
 #endif
