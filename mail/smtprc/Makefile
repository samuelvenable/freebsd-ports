PORTNAME=	smtprc
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Scanner for open SMTP relays
WWW=		http://smtprc.sourceforge.net

USES=		tar:tgz

OPTIONS_DEFINE=	DOCS GUI

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
RUN_DEPENDS=	p5-Tk>=0:x11-toolkits/p5-Tk
PLIST_SUB+=	WITHGUI=""
.else
PLIST_SUB+=	WITHGUI="@comment "
.endif

pre-fetch:
.if ${PORT_OPTIONS:MGUI}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Installed with GUI"
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press ctrl-c now, and define WITH_GUI for GUI"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,-Wall -g,${CFLAGS},g ; \
	    s,gcc,${CC},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/auto.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/auto.conf.sample
	${INSTALL_DATA} ${WRKSRC}/email.tmpl ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/email.tmpl.sample
	${INSTALL_DATA} ${WRKSRC}/rcheck.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/rcheck.conf.sample
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_SCRIPT} ${WRKSRC}/gsmtprc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gsmtprc.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endif
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
