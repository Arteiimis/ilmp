add_rules("mode.debug", "mode.release")

if is_plat("linux") then
    set_installdir("/usr")
end

target("ilmp")
    set_kind("$(kind)")

    add_files("ilmp/*.c", "ilmp/masm/*.asm")
    add_includedirs("ilmp", "ilmp/masm")
    add_cflags("-O2")

    if is_plat("windows", "mingw") and is_kind("shared") then
        add_files("ilmp/*.def")
    end

    add_installfiles("ilmp/*.h", {prefixdir = "include/ilmp"})
target_end()

target("ilmPi")
    set_kind("static")

    add_deps("ilmp")
    add_includedirs("ilmPi")
    add_files("ilmPi/*.cpp|examples.cpp")

    add_installfiles("ilmPi/*.h", {prefixdir = "include/ilmp"})
target_end()