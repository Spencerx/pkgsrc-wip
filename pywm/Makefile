# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=		pywm-0.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		wm
MASTER_SITES=		http://www.freenet.org.nz/python/pywm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freenet.org.nz/python/pywm/
COMMENT=		Window manager in Python

TOOL_DEPENDS=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	27 # py-pyrex

.include "../../lang/python/extension.mk"
.include "../../wip/fltk11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
