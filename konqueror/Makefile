# $NetBSD: Makefile,v 1.16 2025/02/12 06:45:39 ryoon Exp $

DISTNAME=	konqueror-${KAPPSVER}
CATEGORIES=	www

HOMEPAGE=	https://konqueror.org/
COMMENT=	KDE File Manager & Web Browser
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

KAPPSVER=	25.04.0
.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=5.19.0:../../devel/kf6-kdoctools
#DEPENDS+=	kf6-kinit>=5.19.0:../../x11/kf6-kinit

USE_TOOLS+=	msgmerge

#SUBST_CLASSES+=		fix-moc
#SUBST_STAGE.fix-moc=	post-configure
#SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
#SUBST_FILES.fix-moc=	_KDE_build/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
#SUBST_NOOP_OK.fix-moc=	yes
#SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_FILES.xdg+=	settings/konqhtml/CMakeLists.txt
SUBST_FILES.xdg+=	sidebar/CMakeLists.txt
SUBST_FILES.xdg+=	plugins/babelfish/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_AUTOSTARTDIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'
SUBST_SED.xdg+=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/konqy_preload.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/konqy_preload.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/konqsidebartngrc \
		${PKG_SYSCONFDIR}/xdg/konqsidebartngrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/translaterc \
		${PKG_SYSCONFDIR}/xdg/translaterc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/useragenttemplatesrc \
		${PKG_SYSCONFDIR}/xdg/useragenttemplatesrc

# list of hunspell dictionaries to support
# eg.   en_US en_GB en_NZ
KONQ_DICTS?=
.for dict in ${KONQ_DICTS}
DEPENDS+=		hunspell-${dict}-[0-9]*:../../textproc/hunspell-${dict}
GENERATE_PLIST+=	${ECHO} share/konqueror/webengine_dictionaries/${dict}.bdic;
.endfor

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kdoctools/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/kf6-kdesu/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../x11/kf6-kactivities/buildlink3.mk"
#.include "../../x11/qt6-qtscript/buildlink3.mk"
.include "../../wip/qt6-qtwebengine/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
