PORTNAME=	frogatto
PORTVERSION=	1.3.1
PORTREVISION=	33
CATEGORIES=	games

MAINTAINER=	fiziologus@gmail.com
COMMENT=	Old-school 2D classic adventure platformer game
WWW=		https://www.frogatto.com/

LICENSE=	FROGATTO GPLv3
LICENSE_COMB=	multi
LICENSE_NAME_FROGATTO=	Frogatto license
LICENSE_FILE_FROGATTO=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv3=	${WRKSRC}/src/LICENSE
LICENSE_PERMS_FROGATTO=	dist-mirror pkg-mirror auto-accept

BROKEN=		fails to build with Boost>=1.87

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libpng.so:graphics/png

USES=		compiler:c++11-lang dos2unix gl gmake pkgconfig sdl
ALL_TARGET=	game server
USE_GITHUB=	yes
USE_GL=		glew glu
USE_SDL=	sdl image mixer ttf
USE_CXXSTD=	c++11
DOS2UNIX_FILES=	src/surface_cache.cpp

PLIST_FILES=	bin/${PORTNAME} bin/${PORTNAME}-server

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,%lu,%u,' ${WRKSRC}/src/server.cpp
	@${REINPLACE_CMD} -e 's,__linux__,__${OPSYS}__,' \
		${WRKSRC}/src/clipboard.cpp
# Point to the right location where to look for resources on FreeBSD
	@${REINPLACE_CMD} -e 's,HAVE_CONFIG_H,__FreeBSD__,' \
		-e 's,DATADIR,"${DATADIR}",' ${WRKSRC}/src/filesystem.cpp
	@${REINPLACE_CMD} -e 's,itor->second,"${DATADIR}/" + &,' \
		${WRKSRC}/src/sound.cpp
	@${REINPLACE_CMD} -e '/\/locale\//s,\.,${PREFIX}/share,' \
		${WRKSRC}/src/i18n.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/game ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/server \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-server
	cd ${WRKSRC}/modules/frogatto/locale && \
		${MV} hu_HU hu && ${MV} ms_MY ms
	cd ${WRKSRC}/modules/frogatto && ${COPYTREE_SHARE} \
		locale ${STAGEDIR}${PREFIX}/share
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data images music modules utils" \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf *.cfg ${STAGEDIR}${DATADIR}
# Dynamically generate part of the PLIST for NLS files and game resources
# (really lots of them)
	@${FIND} ${STAGEDIR}${PREFIX}/share/locale -name ${PORTNAME}.mo | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' | ${SORT} >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${DATADIR} -not -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' | ${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
