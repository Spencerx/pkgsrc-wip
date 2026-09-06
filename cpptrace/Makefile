# $NetBSD$

DISTNAME=	cpptrace-1.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jeremy-rifkin/}
GITHUB_PROJECT=	cpptrace
GITHUB_TAG=	v1.0.4

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://github.com/jeremy-rifkin/cpptrace
COMMENT=	Simple, portable, and self-contained stacktrace library for C++11+
LICENSE=	mit

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_MODULE_PATH:STRING=${WRKSRC}/cmake
CMAKE_CONFIGURE_ARGS+=	-DCPPTRACE_USE_EXTERNAL_ZSTD:BOOL=TRUE
CMAKE_CONFIGURE_ARGS+=	-DCPPTRACE_USE_EXTERNAL_LIBDWARF:BOOL=TRUE
CMAKE_CONFIGURE_ARGS+=	-DCPPTRACE_FIND_LIBDWARF_WITH_PKGCONFIG:BOOL=TRUE

.include "../../mk/bsd.prefs.mk"

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libdwarf/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
