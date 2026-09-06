# $NetBSD$

VERSION=	2.2.1
PKGNAME=	libassert-${VERSION}
DISTNAME=	libassert-v${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jeremy-rifkin/}
GITHUB_PROJECT=	libassert
GITHUB_TAG=	v${VERSION}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://github.com/jeremy-rifkin/libassert
COMMENT=	The most over-engineered C++ assertion library
LICENSE=	mit

USE_LANGUAGES=	c++

CMAKE_CONFIGURE_ARGS+=	-DLIBASSERT_USE_EXTERNAL_CPPTRACE:BOOL=TRUE

.include "../../mk/bsd.prefs.mk"

.include "../../devel/catch2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../wip/cpptrace/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
