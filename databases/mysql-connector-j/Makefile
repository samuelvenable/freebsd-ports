PORTNAME=	mysql-connector-j
PORTVERSION=	9.0.0
CATEGORIES=	databases java
MASTER_SITES=	MYSQL/Connector-J

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	MySQL Connector/J: JDBC interface for MySQL
WWW=		https://dev.mysql.com/downloads/connector/j/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${JAVALIBDIR}/slf4j-api.jar:devel/slf4j \
		${JAVALIBDIR}/c3p0.jar:databases/c3p0 \
		${JAVALIBDIR}/protobuf-java.jar:devel/protobuf-java

USES=		cpe java
CPE_VENDOR=	oracle
CPE_PRODUCT=	mysql_connector_j

NO_ARCH=	yes
NO_BUILD=	yes

CONFLICTS_INSTALL=	mysql-connector-java51 # share/java/classes/mysql-connector-java.jar

EXTRADOCS=	CHANGES

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@for extradoc in ${EXTRADOCS} ; do \
	  ${INSTALL_DATA} ${INSTALL_WRKSRC}/$$extradoc ${STAGEDIR}${DOCSDIR} ; \
	done

.include <bsd.port.mk>
