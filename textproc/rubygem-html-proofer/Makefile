PORTNAME=	html-proofer
PORTVERSION=	5.0.10
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test your rendered HTML files
WWW=		https://github.com/gjtorikian/html-proofer

LICENSE=	MIT

RUN_DEPENDS=	rubygem-addressable>=2.3<3:www/rubygem-addressable \
		rubygem-async>=2.1<3:devel/rubygem-async \
		rubygem-nokogiri>=1.13<2:textproc/rubygem-nokogiri \
		rubygem-pdf-reader>=2.11<3:print/rubygem-pdf-reader \
		rubygem-rainbow>=3.0<4:devel/rubygem-rainbow \
		rubygem-typhoeus>=1.3<2:www/rubygem-typhoeus \
		rubygem-yell>=2.0<3:sysutils/rubygem-yell \
		rubygem-zeitwerk>=2.5<3:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/htmlproofer

.include <bsd.port.mk>
