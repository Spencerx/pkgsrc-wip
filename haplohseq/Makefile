# $NetBSD: Makefile,v 1.5 2025/03/06 01:19:04 bacon Exp $

DISTNAME=	haplohseq-0.1.2.5
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_PROJECT=	haplohseq
GITHUB_TAG=	5cdedc2401a00117eaffc29fa0a05c517debfded

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/integrativecancergenomics/software/haplohseq
COMMENT=	Identify regions of allelic imbalance
LICENSE=	mit

SUBST_CLASSES+=		test
SUBST_STAGE.test=	pre-configure
SUBST_SED.test=		-e 's|\.\./haplohseq|haplohseq|'
SUBST_SED.test+=	-e 's|python|${PYTHONBIN}|'
SUBST_FILES.test=	example/example_run.sh

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++14	# Minimum for boost, maximum for haplohseq
FORCE_CXX_STD+=		c++14
USE_TOOLS+=		gmake pax
MAKE_FILE=		makefile

EXAMPLESDIR=	${PREFIX}/share/examples/haplohseq

INSTALLATION_DIRS=	share/examples/haplohseq

post-patch:
	${SED} -e "s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|" \
		${FILESDIR}/haplohseq-example.in > ${WRKDIR}/haplohseq-example

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/haplohseq-example ${DESTDIR}${PREFIX}/bin
	(cd ${WRKSRC} && pax -rw example ldmap scripts ${DESTDIR}${EXAMPLESDIR})

do-test:
	(cd ${WRKSRC}/build/test && ${SH} ${WRKSRC}/src/test/run-tests)

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
