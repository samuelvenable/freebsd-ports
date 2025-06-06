PORTNAME=	xNetHack
DISTVERSIONPREFIX=	xnh
DISTVERSION=	9.0
CATEGORIES=	games

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Experimental features and improvements applied to NetHack 3.7-dev
WWW=		https://nethackwiki.com/wiki/XNetHack

LICENSE=	nethack
LICENSE_NAME=	NETHACK GENERAL PUBLIC LICENSE
LICENSE_FILE=	${WRKSRC}/dat/license
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

FLAVORS=	x11 nox11 qt
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11
qt_PKGNAMESUFFIX=	-qt

BUILD_DEPENDS=	nroff:textproc/groff

USES=		alias compiler:c11 gmake ncurses tar:tgz lua:54
USE_GITHUB=	yes
GH_ACCOUNT=	copperwater

MAKE_ENV=	GRAPHICS="${GRAPHICS}"
PLIST_SUB=	HACKNAME="${HACKNAME}"

# Configure these variables as you want them to be.
HACKNAME?=	${PORTNAME:tl}
HACKDIR?=	share/${HACKNAME}

DATADIR=	${PREFIX}/${HACKDIR}
DOCSDIR=	${PREFIX}/share/doc/${HACKNAME}

.if ${FLAVOR} == "x11"
USES+=		xorg
USE_XORG=	xaw xpm xmu xext xt x11 sm ice
CFLAGS+=	-DUSE_TILES
GRAPHICS=	X11_GRAPHICS
.elif ${FLAVOR} == "nox11"
GRAPHICS=	# none
.elif ${FLAVOR} == "qt"
USES+=		localbase pkgconfig qt:5
USE_QT=		buildtools:build core gui multimedia network widgets
MAKE_ENV+=	LINK=${CXX} QTDIR=${LOCALBASE}/${QT_ARCHDIR_REL}
CFLAGS+=	-I${QT_INCDIR} -DSND_LIB_QTSOUND
CXXFLAGS+=	-fpic -I${QT_INCDIR} -DQT_WIDGETS_LIB -DQT_MULTIMEDIA_LIB \
		-DQT_NETWORK_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DSND_LIB_QTSOUND
GRAPHICS=	QT_GRAPHICS
.endif

CFLAGS+=	-DNOMAIL -DCURSES_GRAPHICS

# nhlua.c has a (patched out) version check for lua when the sandbox
# is used.  As I cannot ascertain whether using the system's different
# lua version could cause problems, I'll leave the sandbox disabled by
# default.
OPTIONS_DEFINE=	DOCS SANDBOX
SANDBOX_DESC=	Run lua in a sandbox (untested)
SANDBOX_CFLAGS=	-DNHL_SANDBOX

.include <bsd.port.pre.mk>

pre-configure:
.for f in include/config.h sys/unix/Makefile.top
	@${REINPLACE_CMD} -e 's|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' \
		${WRKSRC}/${f}
.endfor
.if defined(WITHOUT_SHELL)
	@${REINPLACE_CMD} -e 's|#define SHELL|/* #define SHELL */|' ${WRKSRC}/include/unixconf.h
.endif
.if defined(WITH_MAIL)
	@${REINPLACE_CMD} -e 's|/\* #define MAIL \*/|#define MAIL|' ${WRKSRC}/include/unixconf.h
.endif

do-configure:
	${TOUCH} ${WRKSRC}/dat/gitinfo.txt
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/recover
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/${HACKNAME}
	@cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} manpages
	${MKDIR} ${STAGEDIR}${DATADIR}/save
	${CP} ${WRKSRC}/sys/unix/sysconf ${STAGEDIR}/${DATADIR}/sysconf
.for f in livelog logfile record sysconf xlogfile
	${CP} ${STAGEDIR}/${DATADIR}/${f} ${STAGEDIR}/${DATADIR}/${f}.sample
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
