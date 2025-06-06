PORTNAME=	vtun
PORTVERSION=	3.0.4
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	SF \
		LOCAL/mat/vtun

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping
WWW=		https://vtun.sourceforge.net/

LICENSE=	GPLv2

DEPRECATED=	Upstream is dead and last release in 2016
EXPIRATION_DATE=2025-06-30

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

USES=		autoreconf localbase ssl
USE_RC_SUBR=	vtunclient vtund
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFIGURE_ARGS=	--localstatedir=/var \
		--with-lzo-headers=${LOCALBASE}/include/lzo \
		--with-lzo-lib=${LOCALBASE}/lib \
		--with-ssl-headers=${OPENSSLINC} \
		--with-ssl-lib=${OPENSSLLIB}
CONFIGURE_ENV=	YACC=${YACC}

ALL_TARGET=	vtund

CFLAGS+=	-ansi -Wno-pointer-sign

PORTDOCS=	ChangeLog Credits FAQ README README.LZO README.Setup \
		README.Shaper TODO

OPTIONS_DEFINE=	DOCS

# Extended mode patches, obtained from
# http://home.jp.FreeBSD.org/~simokawa/vtun-v6.html
# are now dynamically enabled using the -e option.

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$\(SSL_HDR_DIR\)|$$\1 $$\1/openssl|g' \
		-e 's|$$\(BLOWFISH_HDR_DIR\)|$$\1 $$SSL_HDR_DIR/openssl|g' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/vtund
	${INSTALL_DATA} ${WRKSRC}/vtund.conf ${STAGEDIR}${PREFIX}/etc/vtund.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man8/vtund.8 ${STAGEDIR}${PREFIX}/share/man/man1/vtun.1

post-install-DOCS-on:
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
