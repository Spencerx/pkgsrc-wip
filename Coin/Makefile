# $NetBSD$

DISTNAME=		Coin-4.0.3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=coin3d/}
GITHUB_PROJECT=		coin
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.coin3d.org/
COMMENT=		Free, portable, Open Inventor API implementation
LICENSE=		modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_CXX_FEATURES=	c++11

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
CONFIGURE_ARGS+=	--with-pthread=yes
CONFIGURE_ARGS+=	--enable-threadsafe
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--without-framework
.endif

.include "../../devel/cmake/build.mk"

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/simage/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
