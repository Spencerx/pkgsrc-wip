$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/threading/platform_thread_posix.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/base/threading/platform_thread_posix.cc
@@ -78,12 +78,12 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::DisallowSingleton();
 
-#if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && BUILDFLAG(USE_STARSCAN)
+#if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && BUILDFLAG(USE_STARSCAN) && !BUILDFLAG(IS_BSD)
     partition_alloc::internal::PCScan::NotifyThreadCreated(
         partition_alloc::internal::GetStackPointer());
 #endif
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_APPLE)
     PlatformThread::SetCurrentThreadRealtimePeriodValue(
         delegate->GetRealtimePeriod());
@@ -267,6 +267,8 @@ PlatformThreadId PlatformThreadBase::Cur
   return reinterpret_cast<int32_t>(pthread_self());
 #elif BUILDFLAG(IS_POSIX) && BUILDFLAG(IS_AIX)
   return pthread_self();
+#elif BUILDFLAG(IS_BSD)
+  return reinterpret_cast<uint64_t>(pthread_self());
 #elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_AIX)
   return reinterpret_cast<int64_t>(pthread_self());
 #endif
@@ -357,7 +359,7 @@ void PlatformThreadBase::Detach(Platform
 
 // static
 bool PlatformThreadBase::CanChangeThreadType(ThreadType from, ThreadType to) {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   return false;
 #else
   if (from >= to) {
@@ -378,6 +380,9 @@ void SetCurrentThreadTypeImpl(ThreadType
                               MessagePumpType pump_type_hint) {
 #if BUILDFLAG(IS_NACL)
   NOTIMPLEMENTED();
+// avoid pledge(2) violation
+#elif BUILDFLAG(IS_BSD)
+   NOTIMPLEMENTED();
 #else
   if (internal::SetCurrentThreadTypeForPlatform(thread_type, pump_type_hint))
     return;
@@ -400,7 +405,7 @@ void SetCurrentThreadTypeImpl(ThreadType
 
 // static
 ThreadPriorityForTest PlatformThreadBase::GetCurrentThreadPriorityForTest() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return ThreadPriorityForTest::kNormal;
 #else
