$NetBSD$

Treat NetBSD the same as Linux.

--- src/binary/elf.cpp.orig	2026-09-06 08:54:39.304728113 +0000
+++ src/binary/elf.cpp
@@ -7,7 +7,7 @@
 #include "utils/io/file.hpp"
 #include "utils/string_view.hpp"
 
-#if IS_LINUX
+#if IS_LINUX || IS_NETBSD
 
 #include <array>
 #include <cstdint>
