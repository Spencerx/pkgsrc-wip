# $NetBSD: Makefile,v 1.93 2025/01/20 23:39:20 gdt Exp $

DISTNAME=	LibreCAD-2.2.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=LibreCAD/}
GITHUB_PROJECT=	LibreCAD
GITHUB_TAG=	${DISTNAME:S/LibreCAD-//g}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://librecad.org/
COMMENT=	Free Open Source personal CAD application
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

EXTRACT_USING=	bsdtar

USE_LANGUAGES=	c c++
# Upstream declares that c++17 is required in librecad.pro and adds -std.
# Some subdirectories apparently use -std=gnu++1z.
USE_CXX_FEATURES+=	c++17
USE_CXX_FEATURES+=	gnu++1z

USE_TOOLS+=	pax pkg-config
USE_LIBTOOL=	yes

SUBST_CLASSES+=		qtdir
SUBST_STAGE.qtdir=	pre-configure
SUBST_MESSAGE.qtdir=	Set qt5/bin
SUBST_FILES.qtdir+=	scripts/postprocess-unix.sh
SUBST_VARS.qtdir+=	QTDIR

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mclang*)
BUILDLINK_TRANSFORM+=   rm:-fext-numeric-literals
.endif

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/${PKGBASE}
INSTALLATION_DIRS+=	lib/${PKGBASE}

QMAKE_OPTIONS+=	CONFIG+=release
# This doesn't seem right.  Probably we should be using
# BUILDLINK_PREFIX.boost-libs but that's empty.
#QMAKE_OPTIONS+=	BOOST_DIR=${PREFIX}
#QMAKE_OPTIONS+=	BOOST_LIBDIR=${PREFIX}/lib
#QMAKE_OPTIONS+=	MUPARSER_DIR=${PREFIX}
QMAKE_OPTIONS+=	QMAKE_LFLAGS_RELEASE=
QMAKE_OPTIONS+=	DISABLE_POSTSCRIPT=true

do-configure:
	${RUN} cd ${WRKSRC} && ${QTDIR}/bin/qmake ${QMAKE_OPTIONS:Q}
	${RUN} cd ${WRKSRC}/plugins && ${QTDIR}/bin/qmake \
		INSTALLS+=target target.path=${PREFIX}/lib/librecad/plugins

do-install:
	${RUN} cd ${WRKSRC} && ./scripts/postprocess-unix.sh
	${INSTALL_PROGRAM} ${WRKSRC}/unix/librecad \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/ttf2lff \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/desktop/librecad.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/desktop/librecad.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/tools/ttf2lff/ttf2lff.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${RUN} cd ${WRKSRC}/plugins && \
	    ${SETENV} ${MAKE_ENV} ${MAKE} INSTALL_ROOT=${DESTDIR} install
	${RUN} cd ${WRKSRC}/unix/resources && ${PAX} -rwpm fonts \
	    ${DESTDIR}${PREFIX}/lib/librecad
	${RUN} cd ${WRKSRC}/unix/resources && ${PAX} -rwpm library patterns qm \
	    ${DESTDIR}${PREFIX}/share/librecad

.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/muparser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
