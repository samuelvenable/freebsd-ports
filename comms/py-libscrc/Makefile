PORTNAME=	libscrc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zarychtam@plan-b.pwste.edu.pl
COMMENT=	Python library for calculating various types of CRC
WWW=		https://github.com/hex-in/libscrc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	hex-in
USE_PYTHON=	autoplist distutils

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	@cd ${TEST_WRKSRC} && for test in \
	libscrc/test/canx.py \
	libscrc/test/crc8.py \
	libscrc/test/crc16.py \
	libscrc/test/crc24.py \
	libscrc/test/crc32.py \
	libscrc/test/crc64.py \
	libscrc/test/crcx.py \
	libscrc/test/hacker.py \
	libscrc/test/modbus.py; \
	do ${SETENV} ${TEST_ENV} ${PYTHON_CMD} $${test}; done

.include <bsd.port.mk>
