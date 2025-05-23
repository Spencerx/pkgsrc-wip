# $NetBSD: Makefile,v 1.22 2024/08/03 19:28:29 bsiegert Exp $

PKGNAME=	go-bin-1.22.10
CATEGORIES=	lang
MASTER_SITES=	https://dl.google.com/go/

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://golang.org/
COMMENT=	Bootstrap toolchain for lang/go*
LICENSE=	modified-bsd

NO_BUILD=	yes
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC
USE_LANGUAGES=	# none
USE_TOOLS+=	pax perl:run bash:run
WRKSRC=		${WRKDIR}/go

.include "../../lang/go/go-vars.mk"

REPLACE_PERL+=			src/*/*.pl src/*/*/*.pl
REPLACE_PERL+=			src/net/http/cgi/testdata/test.cgi
REPLACE_BASH+=			*/*.bash */*/*.bash */*/*/*.bash */*/*/*/*.bash
REPLACE_BASH+=			*/*/*/*/*/*/*.bash */*/*/*/*/*/*/*.bash
REPLACE_BASH+=			*/*/*.sh */*/*/*.sh */*/*/*/*.sh */*/*/*/*/*/*/*.sh
REPLACE_BASH+=			misc/arm/a misc/wasm/go_js_wasm_exec
REPLACE_BASH+=			misc/wasm/go_wasip1_wasm_exec
CHECK_INTERPRETER_SKIP+=	*/*.rc
CHECK_PORTABILITY_SKIP+=	misc/ios/clangwrap.sh
CHECK_SHLIBS_SUPPORTED=		no
CHECK_RELRO_SUPPORTED=		no

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM+=		Darwin-*-x86_64
DIST.darwin-amd64=		go${PKGVERSION_NOREV}.darwin-amd64.tar.gz
.if ${MACHINE_PLATFORM:MDarwin-*-x86_64} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.darwin-amd64}
EXTRACT_ONLY+=			${DIST.darwin-amd64}
.endif

ONLY_FOR_PLATFORM+=		Darwin-*-aarch64
DIST.darwin-arm64=		go${PKGVERSION_NOREV}.darwin-arm64.tar.gz
.if ${MACHINE_PLATFORM:MDarwin-*-aarch64} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.darwin-arm64}
EXTRACT_ONLY+=			${DIST.darwin-arm64}
.endif

ONLY_FOR_PLATFORM+=		FreeBSD-*-i386
DIST.freebsd-386=		go${PKGVERSION_NOREV}.freebsd-386.tar.gz
.if ${MACHINE_PLATFORM:MFreeBSD-*-i386} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.freebsd-386}
EXTRACT_ONLY+=			${DIST.freebsd-386}
.endif

ONLY_FOR_PLATFORM+=		FreeBSD-*-x86_64
DIST.freebsd-amd64=		go${PKGVERSION_NOREV}.freebsd-amd64.tar.gz
.if ${MACHINE_PLATFORM:MFreeBSD-*-x86_64} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.freebsd-amd64}
EXTRACT_ONLY+=			${DIST.freebsd-amd64}
.endif

ONLY_FOR_PLATFORM+=		FreeBSD-*-*arm*
DIST.freebsd-arm=		go${PKGVERSION_NOREV}.freebsd-arm.tar.gz
.if ${MACHINE_PLATFORM:MFreeBSD-*-*arm*} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.freebsd-arm}
EXTRACT_ONLY+=			${DIST.freebsd-arm}
.endif

ONLY_FOR_PLATFORM+=		FreeBSD-*-aarch64
DIST.freebsd-arm64=		go${PKGVERSION_NOREV}.freebsd-arm64.tar.gz
.if ${MACHINE_PLATFORM:MFreeBSD-*-aarch64} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.freebsd-arm64}
EXTRACT_ONLY+=			${DIST.freebsd-arm64}
.endif

ONLY_FOR_PLATFORM+=		Linux-*-i386
DIST.linux-386=			go${PKGVERSION_NOREV}.linux-386.tar.gz
.if ${MACHINE_PLATFORM:MLinux-*-i386} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.linux-386}
EXTRACT_ONLY+=			${DIST.linux-386}
.endif

ONLY_FOR_PLATFORM+=		Linux-*-x86_64
DIST.linux-amd64=		go${PKGVERSION_NOREV}.linux-amd64.tar.gz
.if ${MACHINE_PLATFORM:MLinux-*-x86_64} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.linux-amd64}
EXTRACT_ONLY+=			${DIST.linux-amd64}
.endif

ONLY_FOR_PLATFORM+=		Linux-*-*arm*
DIST.linux-armv6l=		go${PKGVERSION_NOREV}.linux-armv6l.tar.gz
.if ${MACHINE_PLATFORM:MLinux-*-*arm*} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.linux-armv6l}
EXTRACT_ONLY+=			${DIST.linux-armv6l}
.endif

ONLY_FOR_PLATFORM+=		Linux-*-aarch64
DIST.linux-arm64=		go${PKGVERSION_NOREV}.linux-arm64.tar.gz
.if ${MACHINE_PLATFORM:MLinux-*-aarch64} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.linux-arm64}
EXTRACT_ONLY+=			${DIST.linux-arm64}
.endif

ONLY_FOR_PLATFORM+=		NetBSD-*-aarch64
DIST.netbsd-arm64=		go${PKGVERSION_NOREV}.netbsd-arm64.tar.gz
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.netbsd-arm64}
EXTRACT_ONLY+=			${DIST.netbsd-arm64}
.endif

ONLY_FOR_PLATFORM+=		SunOS-*-x86_64
DIST.illumos-amd64=		go1.21.8.illumos-amd64.tar.gz
SITES.${DIST.illumos-amd64}=	https://us-central.manta.mnx.io/pkgsrc/public/pkg-bootstraps/
.if ${MACHINE_PLATFORM:MSunOS-*-x86_64} || make(distinfo) || make(mdi)
DISTFILES+=			${DIST.illumos-amd64}
EXTRACT_ONLY+=			${DIST.illumos-amd64}
.endif

INSTALLATION_DIRS+=	go-bin

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/go-bin
#
# Removing the signatures is required to operate inside a chroot, but breaks
# running them outside.  We're left with no choice but to make it configurable
# by the user.
#
.if ${MACHINE_PLATFORM:MDarwin-*-*} && defined(DARWIN_CHROOTED)
	for f in ${DESTDIR}${PREFIX}/go-bin/bin/* \
		 ${DESTDIR}${PREFIX}/go-bin/pkg/tool/darwin_*/*; do \
		/usr/bin/codesign --remove-signature $$f; \
	done
.endif

post-install:
	cd ${DESTDIR}${PREFIX} && find go-bin -type f -print	\
	    > ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
