$NetBSD$

Treat NetBSD the same as Linux.

--- src/binary/elf.hpp.orig	2026-09-06 08:54:12.816180746 +0000
+++ src/binary/elf.hpp
@@ -7,7 +7,7 @@
 #include "utils/span.hpp"
 #include "utils/utils.hpp"
 
-#if IS_LINUX
+#if IS_LINUX || IS_NETBSD
 
 #include <cstdint>
 #include <string>
