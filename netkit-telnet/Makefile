# $NetBSD: Makefile,v 1.10 2015/04/25 12:36:42 krytarowski Exp $

DISTNAME=		netkit-telnet-0.17
CATEGORIES=		net
MASTER_SITES=		http://ibiblio.org/pub/linux/system/network/netkit/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/
COMMENT=		The telnet and telnetd for Linux

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
ONLY_FOR_PLATFORM=	Linux-*-* Darwin-*-*

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--installroot=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
