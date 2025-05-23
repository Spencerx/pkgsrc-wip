$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/password_manager/core/browser/password_store/login_database.cc.orig	2024-10-18 12:34:07.242155800 +0000
+++ components/password_manager/core/browser/password_store/login_database.cc
@@ -1028,7 +1028,7 @@ bool ShouldDeleteUndecryptablePasswords(
         clearing_undecryptable_passwords,
     bool is_user_data_dir_policy_set,
     bool is_disabled_by_policy) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string user_data_dir_string;
   std::unique_ptr<base::Environment> environment(base::Environment::Create());
   // On Linux user data directory ca be specified using an env variable. If it
@@ -1047,7 +1047,7 @@ bool ShouldDeleteUndecryptablePasswords(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch(password_manager::kPasswordStore)) {
     RecordShouldDeleteUndecryptablePasswordsMetric(
         ShouldDeleteUndecryptablePasswordsResult::
