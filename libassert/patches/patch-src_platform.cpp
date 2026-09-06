$NetBSD$

Add support for NetBSD.

--- src/platform.cpp.orig	2026-09-06 09:40:24.074538397 +0000
+++ src/platform.cpp
@@ -22,6 +22,12 @@
  #include <fcntl.h>
  #include <sys/ioctl.h>
  #include <unistd.h>
+#elif IS_NETBSD
+ #include <charconv>
+ #include <sys/ioctl.h>
+ #include <sys/param.h>
+ #include <sys/sysctl.h>
+ #include <unistd.h>
 #elif IS_APPLE
  #include <sys/ioctl.h>
  #include <sys/sysctl.h>
@@ -127,6 +133,21 @@ LIBASSERT_BEGIN_NAMESPACE
              return false;
          }
          return false;
+        #elif IS_NETBSD
+         int mib[6];
+         struct kinfo_proc2 kp;
+         size_t len = sizeof(kp);
+         mib[0] = CTL_KERN;
+         mib[1] = KERN_PROC2;
+         mib[2] = KERN_PROC_PID;
+         mib[3] = getpid();
+         mib[4] = sizeof(kp);
+         mib[5] = 1;  // fetch 1 matching process structure
+         if (sysctl(mib, 6, &kp, &len, NULL, 0) == -1) {
+             perror("sysctl");
+             return false;
+         }
+         return (kp.p_flag & P_TRACED) != 0;
         #else
          // https://developer.apple.com/library/archive/qa/qa1361/_index.html
          int mib[4] {CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()};
