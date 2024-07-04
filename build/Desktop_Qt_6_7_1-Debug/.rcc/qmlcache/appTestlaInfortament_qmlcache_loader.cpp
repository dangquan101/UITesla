#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _0x5f_TestlaInfortament_Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_TestlaInfortament_ui_BottomBar_BottomBar_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_TestlaInfortament_ui_RightScreen_RightScreen_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_TestlaInfortament_ui_LeftScreen_LeftScreen_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_TestlaInfortament_ui_RightScreen_NavigationSearchBox_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_TestlaInfortament_ui_BottomBar_HVAComponent_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_TestlaInfortament_ui_BottomBar_VolumControlerComponent_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/TestlaInfortament/Main.qml"), &QmlCacheGeneratedCode::_0x5f_TestlaInfortament_Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/TestlaInfortament/ui/BottomBar/BottomBar.qml"), &QmlCacheGeneratedCode::_0x5f_TestlaInfortament_ui_BottomBar_BottomBar_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/TestlaInfortament/ui/RightScreen/RightScreen.qml"), &QmlCacheGeneratedCode::_0x5f_TestlaInfortament_ui_RightScreen_RightScreen_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/TestlaInfortament/ui/LeftScreen/LeftScreen.qml"), &QmlCacheGeneratedCode::_0x5f_TestlaInfortament_ui_LeftScreen_LeftScreen_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/TestlaInfortament/ui/RightScreen/NavigationSearchBox.qml"), &QmlCacheGeneratedCode::_0x5f_TestlaInfortament_ui_RightScreen_NavigationSearchBox_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/TestlaInfortament/ui/BottomBar/HVAComponent.qml"), &QmlCacheGeneratedCode::_0x5f_TestlaInfortament_ui_BottomBar_HVAComponent_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/TestlaInfortament/ui/BottomBar/VolumControlerComponent.qml"), &QmlCacheGeneratedCode::_0x5f_TestlaInfortament_ui_BottomBar_VolumControlerComponent_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appTestlaInfortament)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appTestlaInfortament))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appTestlaInfortament)() {
    return 1;
}
