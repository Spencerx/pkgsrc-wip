$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/perfetto/src/base/subprocess_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/src/base/subprocess_posix.cc
@@ -35,7 +35,8 @@
 #include <thread>
 #include <tuple>
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 #endif
@@ -64,7 +65,8 @@ struct ChildProcessArgs {
 // Don't add any dynamic allocation in this function. This will be invoked
 // under a fork(), potentially in a state where the allocator lock is held.
 void __attribute__((noreturn)) ChildProcess(ChildProcessArgs* args) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
   // In no case we want a child process to outlive its parent process. This is
   // relevant for tests, so that a test failure/crash doesn't leave child
