$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/stack_trace_posix.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/stack_trace_posix.cc
@@ -13,11 +13,11 @@
 #include "partition_alloc/partition_alloc_base/posix/eintr_wrapper.h"
 #include "partition_alloc/partition_alloc_base/strings/safe_sprintf.h"
 
-#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 #include <link.h>  // For ElfW() macro.
 #endif
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 #include <dlfcn.h>
 #endif
 
@@ -25,7 +25,7 @@ namespace partition_alloc::internal::bas
 
 namespace {
 
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 
 // On Android the 'open' function has two versions:
 // int open(const char *pathname, int flags);
@@ -369,7 +369,7 @@ void PrintStackTraceInternal(const void*
 }
 #endif  // !BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 // Since /proc/self/maps is not available, use dladdr() to obtain module
 // names and offsets inside the modules from the given addresses.
 void PrintStackTraceInternal(const void* const* trace, size_t size) {
