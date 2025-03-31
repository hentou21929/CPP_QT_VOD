QT       += core gui
QT += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

CONFIG += c++17
CONFIG += console
DEFINES +=“_HAS_STD_BYTE=0”
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CustomSlider.cpp \
    about.cpp \
    app.cpp \
    close_confirm_dlg.cpp \
    ctrlbar.cpp \
    customthread.cpp \
    displaywind.cpp \
    event_widget.cpp \
    ff_ffplay.cpp \
    ffmsgqueue.cpp \
    globalhelper.cpp \
    httpclient.cpp \
    ijkmediaplayer.cpp \
    left_widget.cpp \
    live_push_window.cpp \
    login_dlg.cpp \
    main.cpp \
    main_window.cpp \
    mainwid.cpp \
    medialist.cpp \
    my_line_edit.cpp \
    my_line_edit2.cpp \
    my_push_button.cpp \
    net_image_label.cpp \
    net_image_label2.cpp \
    play_item.cpp \
    playlist.cpp \
    playlistwind.cpp \
    recommand_panel.cpp \
    settingwid.cpp \
    show.cpp \
    title.cpp \
    upload.cpp \
    userdata.cpp \
    videoctl.cpp \
    window-basic-preview.cpp

HEADERS += \
    CustomSlider.h \
    about.h \
    app.h \
    close_confirm_dlg.h \
    ctrlbar.h \
    customthread.h \
    datactl.h \
    display-helpers.hpp \
    displaywind.h \
    event_widget.h \
    ff_fferror.h \
    ff_ffplay.h \
    ffmsg.h \
    ffmsgqueue.h \
    httpclient.h \
    ijkmediaplayer.h \
    left_widget.h \
    live_push_window.h \
    login_dlg.h \
    main_window.h \
    mainwid.h \
    medialist.h \
    my_line_edit.h \
    my_line_edit2.h \
    my_push_button.h \
    net_image_label.h \
    net_image_label2.h \
    play_item.h \
    playlist.h \
    playlistwind.h \
    qrcode/libqrencode/qrencode.h \
    recommand_panel.h \
    resource.h \
    settingwid.h \
    show.h \
    third_party/include/libobs/audio-monitoring/osx/mac-helpers.h \
    third_party/include/libobs/audio-monitoring/pulse/pulseaudio-wrapper.h \
    third_party/include/libobs/audio-monitoring/win32/wasapi-output.h \
    third_party/include/libobs/callback/calldata.h \
    third_party/include/libobs/callback/decl.h \
    third_party/include/libobs/callback/proc.h \
    third_party/include/libobs/callback/signal.h \
    third_party/include/libobs/data/area.effect \
    third_party/include/libobs/data/bicubic_scale.effect \
    third_party/include/libobs/data/bilinear_lowres_scale.effect \
    third_party/include/libobs/data/default.effect \
    third_party/include/libobs/data/default_rect.effect \
    third_party/include/libobs/data/deinterlace_base.effect \
    third_party/include/libobs/data/deinterlace_blend.effect \
    third_party/include/libobs/data/deinterlace_blend_2x.effect \
    third_party/include/libobs/data/deinterlace_discard.effect \
    third_party/include/libobs/data/deinterlace_discard_2x.effect \
    third_party/include/libobs/data/deinterlace_linear.effect \
    third_party/include/libobs/data/deinterlace_linear_2x.effect \
    third_party/include/libobs/data/deinterlace_yadif.effect \
    third_party/include/libobs/data/deinterlace_yadif_2x.effect \
    third_party/include/libobs/data/format_conversion.effect \
    third_party/include/libobs/data/lanczos_scale.effect \
    third_party/include/libobs/data/opaque.effect \
    third_party/include/libobs/graphics/axisang.h \
    third_party/include/libobs/graphics/basemath.hpp \
    third_party/include/libobs/graphics/bounds.h \
    third_party/include/libobs/graphics/device-exports.h \
    third_party/include/libobs/graphics/effect-parser.h \
    third_party/include/libobs/graphics/effect.h \
    third_party/include/libobs/graphics/graphics-internal.h \
    third_party/include/libobs/graphics/graphics.h \
    third_party/include/libobs/graphics/half.h \
    third_party/include/libobs/graphics/image-file.h \
    third_party/include/libobs/graphics/input.h \
    third_party/include/libobs/graphics/libnsgif/libnsgif.h \
    third_party/include/libobs/graphics/math-defs.h \
    third_party/include/libobs/graphics/math-extra.h \
    third_party/include/libobs/graphics/matrix3.h \
    third_party/include/libobs/graphics/matrix4.h \
    third_party/include/libobs/graphics/plane.h \
    third_party/include/libobs/graphics/quat.h \
    third_party/include/libobs/graphics/shader-parser.h \
    third_party/include/libobs/graphics/srgb.h \
    third_party/include/libobs/graphics/vec2.h \
    third_party/include/libobs/graphics/vec3.h \
    third_party/include/libobs/graphics/vec4.h \
    third_party/include/libobs/media-io/audio-io.h \
    third_party/include/libobs/media-io/audio-math.h \
    third_party/include/libobs/media-io/audio-resampler.h \
    third_party/include/libobs/media-io/format-conversion.h \
    third_party/include/libobs/media-io/frame-rate.h \
    third_party/include/libobs/media-io/media-io-defs.h \
    third_party/include/libobs/media-io/media-remux.h \
    third_party/include/libobs/media-io/video-frame.h \
    third_party/include/libobs/media-io/video-io.h \
    third_party/include/libobs/media-io/video-scaler.h \
    third_party/include/libobs/obs-audio-controls.h \
    third_party/include/libobs/obs-av1.h \
    third_party/include/libobs/obs-avc.h \
    third_party/include/libobs/obs-config.h \
    third_party/include/libobs/obs-data.h \
    third_party/include/libobs/obs-defs.h \
    third_party/include/libobs/obs-encoder.h \
    third_party/include/libobs/obs-ffmpeg-compat.h \
    third_party/include/libobs/obs-hevc.h \
    third_party/include/libobs/obs-hotkey.h \
    third_party/include/libobs/obs-hotkeys.h \
    third_party/include/libobs/obs-interaction.h \
    third_party/include/libobs/obs-internal.h \
    third_party/include/libobs/obs-missing-files.h \
    third_party/include/libobs/obs-module.h \
    third_party/include/libobs/obs-nal.h \
    third_party/include/libobs/obs-nix-platform.h \
    third_party/include/libobs/obs-nix-wayland.h \
    third_party/include/libobs/obs-nix-x11.h \
    third_party/include/libobs/obs-nix.h \
    third_party/include/libobs/obs-output.h \
    third_party/include/libobs/obs-properties.h \
    third_party/include/libobs/obs-scene.h \
    third_party/include/libobs/obs-service.h \
    third_party/include/libobs/obs-source.h \
    third_party/include/libobs/obs.h \
    third_party/include/libobs/obs.hpp \
    third_party/include/libobs/obsversion.h \
    third_party/include/libobs/util/apple/cfstring-utils.h \
    third_party/include/libobs/util/array-serializer.h \
    third_party/include/libobs/util/base.h \
    third_party/include/libobs/util/bitstream.h \
    third_party/include/libobs/util/bmem.h \
    third_party/include/libobs/util/buffered-file-serializer.h \
    third_party/include/libobs/util/c99defs.h \
    third_party/include/libobs/util/cf-lexer.h \
    third_party/include/libobs/util/cf-parser.h \
    third_party/include/libobs/util/circlebuf.h \
    third_party/include/libobs/util/config-file.h \
    third_party/include/libobs/util/crc32.h \
    third_party/include/libobs/util/curl/curl-helper.h \
    third_party/include/libobs/util/darray.h \
    third_party/include/libobs/util/deque.h \
    third_party/include/libobs/util/dstr.h \
    third_party/include/libobs/util/dstr.hpp \
    third_party/include/libobs/util/file-serializer.h \
    third_party/include/libobs/util/lexer.h \
    third_party/include/libobs/util/pipe.h \
    third_party/include/libobs/util/platform.h \
    third_party/include/libobs/util/profiler.h \
    third_party/include/libobs/util/profiler.hpp \
    third_party/include/libobs/util/serializer.h \
    third_party/include/libobs/util/simde/check.h \
    third_party/include/libobs/util/simde/debug-trap.h \
    third_party/include/libobs/util/simde/hedley.h \
    third_party/include/libobs/util/simde/simde-align.h \
    third_party/include/libobs/util/simde/simde-arch.h \
    third_party/include/libobs/util/simde/simde-common.h \
    third_party/include/libobs/util/simde/simde-constify.h \
    third_party/include/libobs/util/simde/simde-detect-clang.h \
    third_party/include/libobs/util/simde/simde-diagnostic.h \
    third_party/include/libobs/util/simde/simde-features.h \
    third_party/include/libobs/util/simde/simde-math.h \
    third_party/include/libobs/util/simde/x86/mmx.h \
    third_party/include/libobs/util/simde/x86/sse.h \
    third_party/include/libobs/util/simde/x86/sse2.h \
    third_party/include/libobs/util/sse-intrin.h \
    third_party/include/libobs/util/task.h \
    third_party/include/libobs/util/text-lookup.h \
    third_party/include/libobs/util/threading-posix.h \
    third_party/include/libobs/util/threading-windows.h \
    third_party/include/libobs/util/threading.h \
    third_party/include/libobs/util/utf8.h \
    third_party/include/libobs/util/uthash.h \
    third_party/include/libobs/util/util.hpp \
    third_party/include/libobs/util/util_uint128.h \
    third_party/include/libobs/util/util_uint64.h \
    third_party/include/libobs/util/windows/CoTaskMemPtr.hpp \
    third_party/include/libobs/util/windows/ComPtr.hpp \
    third_party/include/libobs/util/windows/HRError.hpp \
    third_party/include/libobs/util/windows/WinHandle.hpp \
    third_party/include/libobs/util/windows/device-enum.h \
    third_party/include/libobs/util/windows/obfuscate.h \
    third_party/include/libobs/util/windows/win-registry.h \
    third_party/include/libobs/util/windows/win-version.h \
    third_party/include/libobs/util/windows/window-helpers.h \
    title.h \
    upload.h \
    userdata.h \
    videoctl.h

    videoctl.h \

    window-basic-preview.hpp

TRANSLATIONS += \
    bilibili_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DISTFILES += \
    playerdemo.rc \
    res/images/icon.png \
    third_party/include/libobs/cmake/macos/entitlements.plist \
    third_party/include/libobs/data/color.effect \
    third_party/include/libobs/data/premultiplied_alpha.effect \
    third_party/include/libobs/data/repeat.effect \
    third_party/include/libobs/data/solid.effect \
    third_party/include/libobs/graphics/libnsgif/LICENSE.libnsgif \
    third_party/include/libobs/obs-cocoa.m \
    third_party/include/libobs/util/platform-cocoa.m \
    third_party/include/libobs/util/simde/LICENSE.simde \
    third_party/include/libobs/util/simde/README.libobs

INCLUDEPATH += $$PWD/third_party/include/libobs
LIBS += -L$$PWD/third_party/lib -lobs

win32 {
    FFMPEG_HOME=E:\\12\\ffmpeg-7.0.2-full_build-shared
    INCLUDEPATH += $$FFMPEG_HOME/include
    INCLUDEPATH += $$FFMPEG_HOME/include/alibabacloud
    LIBS += -L$$FFMPEG_HOME/lib \
            -lavcodec \
            -lavdevice \
            -lavfilter \
            -lavformat \
            -lavutil \
            -lpostproc \
            -lswresample \
            -lswscale \
            -lalibabacloud-oss-cpp-sdk
}

win32 {
    SDL2_HOME=E:\\12\\SDL2-2.30.8
    INCLUDEPATH += $$SDL2_HOME/include
    LIBS += -L$$SDL2_HOME/lib/x64 \
            -lSDL2 \
            -lSDL2main
}
win32{
    #E:\baidudowmload\aliyun-oss-cpp-sdk-1.10.0\third_party

    INCLUDEPATH += E:/baidudowmload/aliyun-oss-cpp-sdk-1.10.0/third_party/include
    LIBS += -LE:/baidudowmload/aliyun-oss-cpp-sdk-1.10.0/third_party/lib/x64 -llibcurl
    LIBS += -LE:/baidudowmload/aliyun-oss-cpp-sdk-1.10.0/third_party/lib/x64 -llibeay32
    LIBS += -LE:/baidudowmload/aliyun-oss-cpp-sdk-1.10.0/third_party/lib/x64 -lssleay32
}
#win32 {
#    VCPKG_HOME = E:/baidudowmload/vcpkg

#    # 添加头文件路径，包括 OpenSSL
#    INCLUDEPATH += $$VCPKG_HOME/installed/x64-windows/include \
#                   $$VCPKG_HOME/installed/x64-windows/include/openssl

#    # 添加库文件路径，并链接 libcurl, zlib, 以及 OpenSSL 的库
#    LIBS += -L$$VCPKG_HOME/installed/x64-windows/lib \
#            -llibcurl \
#            -lzlib \
#            -llibssl \
#            -llibcrypto
#}



RESOURCES += \
    mainwid.qrc \
    res.qrc

FORMS += \
    about.ui \
    ctrlbar.ui \
    displaywind.ui \
    form.ui \
    mainwid.ui \
    playlist.ui \
    playlistwind.ui \
    settingwid.ui \
    show.ui \
    title.ui \
    upload.ui \



