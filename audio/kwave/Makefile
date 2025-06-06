PORTNAME=	kwave
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sound editor for KDE
WWW=		https://kwave.sourceforge.net/

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libFLAC.so:audio/flac \
		libfftw3.so:math/fftw3 \
		libid3.so:audio/id3lib \
		libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libsamplerate.so:audio/libsamplerate \
		libvorbisenc.so:audio/libvorbis

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		localbase:ldflags pkgconfig qt:6 tar:xz xorg
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons doctools i18n iconthemes itemviews \
		jobwidgets kio service solid sonnet textwidgets widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_GROUP=			AUDIOPLUGIN
OPTIONS_GROUP_AUDIOPLUGIN=	ALSA PULSEAUDIO
ALSA_CMAKE_BOOL=		WITH_ALSA
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
PULSEAUDIO_CMAKE_BOOL=		WITH_PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
