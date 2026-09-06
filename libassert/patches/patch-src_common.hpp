$NetBSD$

Add platform support for NetBSD.

--- src/common.hpp.orig	2026-09-06 09:37:58.975756001 +0000
+++ src/common.hpp
@@ -43,6 +43,7 @@
 
 #define IS_WINDOWS 0
 #define IS_LINUX 0
+#define IS_NETBSD 0
 #define IS_APPLE 0
 
 #if defined(_WIN32)
@@ -51,6 +52,9 @@
 #elif defined(__linux)
  #undef IS_LINUX
  #define IS_LINUX 1
+#elif defined(__NetBSD__)
+ #undef IS_NETBSD
+ #define IS_NETBSD 1
 #elif defined(__APPLE__)
  #undef IS_APPLE
  #define IS_APPLE 1
