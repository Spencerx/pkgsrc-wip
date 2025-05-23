# $NetBSD: Makefile,v 1.49 2023/08/14 05:24:30 wiz Exp $

DISTNAME=	asymptote-3.01
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=asymptote/}
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asymptote.sourceforge.io/
COMMENT=	Powerful descriptive vector graphics language for technical drawings
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

TOOL_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
TOOL_DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
TOOL_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TOOL_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TOOL_DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
TOOL_DEPENDS+=	tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg
TOOL_DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
TOOL_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TOOL_DEPENDS+=	tex-kvsetkeys-[0-9]*:../../print/tex-kvsetkeys
TOOL_DEPENDS+=	tex-media9-[0-9]*:../../print/tex-media9
TOOL_DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
TOOL_DEPENDS+=	tex-parskip-[0-9]*:../../print/tex-parskip
TOOL_DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo
TOOL_DEPENDS+=	tex-texlive-scripts-[0-9]*:../../print/tex-texlive-scripts
TOOL_DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
TOOL_DEPENDS+=	tex-type1cm-[0-9]*:../../print/tex-type1cm
TOOL_DEPENDS+=	ghostscript-agpl>=9.16:../../print/ghostscript-agpl
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry

TEXINFO_REQD+=		6.8

UNLIMIT_RESOURCES=	datasize
#MAKE_JOBS_SAFE=	no # random failure during build as of 2.38

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++11

CONFIGURE_ARGS+=	--enable-gc=system
CONFIGURE_ARGS+=	PYTHON=${PYTHONBIN}
USE_TOOLS+=		bison gmake makeinfo perl
CFLAGS+=		-DGC_NO_THREAD_REDIRECTS

REPLACE_PYTHON+=	GUI/*.py

# only needed on DOS
CHECK_PORTABILITY_SKIP+=	build-scripts/build-asymptote.dos

#
# Ghostscript running in a pipe fails with:
#
# ../asy -dir ../base -config "" -render=0 -f pdf -noprc helix.asy
# GPL Ghostscript 9.53.0:
#   *** EPS files may not contain multiple pages.
#   *** Use of the %d filename format is required to output pages to multiple EPS files.
# GPL Ghostscript 9.53.0: Unrecoverable error, exit code 1
#
# leaving asy hanging indefinitely.
#
NOT_FOR_BULK_PLATFORM+=	SunOS-* NetBSD-*

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xasy.1x \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xasy.1

#.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
# next two could be split off into options
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
# wants library called 'glut', but pkgsrc only provides 'freeglut'
#BUILDLINK_API_DEPENDS.freeglut+=	freeglut>=3.0
#.include "../../graphics/freeglut/buildlink3.mk"
# recognized, but makes asy dump core during creation of documentation
#.include "../../graphics/glut/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
