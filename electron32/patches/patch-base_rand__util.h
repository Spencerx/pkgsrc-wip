$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/rand_util.h.orig	2024-10-18 12:33:59.802254200 +0000
+++ base/rand_util.h
@@ -147,7 +147,7 @@ void RandomShuffle(Itr first, Itr last) 
   std::shuffle(first, last, RandomBitGenerator());
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_BSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
