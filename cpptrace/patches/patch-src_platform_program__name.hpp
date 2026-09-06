$NetBSD$

Treat NetBSD the same as Linux.

--- src/platform/program_name.hpp.orig	2025-07-25 05:41:51.000000000 +0000
+++ src/platform/program_name.hpp
@@ -66,7 +66,7 @@ namespace detail {
 }
 CPPTRACE_END_NAMESPACE
 
-#elif IS_LINUX
+#elif IS_LINUX || IS_NETBSD
 
 #include <sys/types.h>
 #include <unistd.h>
