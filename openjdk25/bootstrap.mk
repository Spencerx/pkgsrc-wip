# $NetBSD: $

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 090000
PKG_FAIL_REASON+=		"Only supports NetBSD >= 9"
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) && ${OPSYS_VERSION} < 090400
PKG_FAIL_REASON+=		"Only supports NetBSD >= 9.4"
.endif

ONLY_FOR_PLATFORM+=		Linux-*-x86_64
BOOT.linux-amd64=		OpenJDK25U-jdk_x64_linux_hotspot_25.0.4.1_1.tar.gz
SITES.${BOOT.linux-amd64}=	https://github.com/adoptium/temurin25-binaries/releases/download/jdk-25.0.4.1%2B1/
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64) || make(distinfo)
DISTFILES+=			${BOOT.linux-amd64}
EXTRACT_ONLY+=			${BOOT.linux-amd64}
ALT_BOOTDIR=			${WRKDIR}/jdk-25.0.4.1+1
.endif

CONFIGURE_ENV+=		LD_LIBRARY_PATH=${ALT_BOOTDIR}/lib

ALT_BOOTDIR?=		${WRKDIR}/bootstrap
