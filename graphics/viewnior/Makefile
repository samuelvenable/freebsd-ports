PORTNAME=	viewnior
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.8
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Fast and simple image viewer
WWW=		https://siyanpanayotov.com/project/viewnior/

LICENSE=	GPLv3

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome \
		meson ninja pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	hellosiyan
GH_PROJECT=	Viewnior

USE_GNOME=	gdkpixbuf glib20 gtk20 intlhack intltool

PORTDOCS=	AUTHORS NEWS README.md

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

pre-configure:
	${MKDIR} ${WRKSRC}/m4

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
