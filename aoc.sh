#!/bin/sh

if [ "$(tput colors 2>/dev/null || echo 0)" -ge 8 ]; then
    RED=$(tput setaf 1)
    GREEN=$(tput setaf 2)
    BLUE=$(tput setaf 4)
    RESET=$(tput sgr0)
    BOLD=$(tput bold)
else
    RED=""
    GREEN=""
    BLUE=""
    RESET=""
    BOLD=""
fi

usage() {
    echo "Usage: $0 <day> [part]"
    echo "  day:  Day number (1-25)"
    echo "  part: Solution part to run (1 or 2, optional - runs both if omitted)"
    exit 1
}

print_header() {
    day=$1
    part=$2
    echo "${BOLD}${BLUE}=== Advent of Code 2024 - Day $day${RESET}"
    [ -n "$part" ] && echo "${BOLD}${BLUE}=== Part $part${RESET}"
    echo
}

cleanup() {
    day=$1
    part=$2
    day_padded=$(printf "%02d" "$day")
    executable="day${day_padded}/solution${part}"
    rm -f "$executable"
}

trap_cleanup() {
    echo
    echo "${BLUE}Cleaning up...${RESET}"
    if [ -n "$running_day" ] && [ -n "$running_part" ]; then
        cleanup "$running_day" "$running_part"
    fi
    exit 1
}

trap trap_cleanup INT TERM

compile_and_run() {
    day=$1
    part=$2
    running_day=$day
    running_part=$part
    day_padded=$(printf "%02d" "$day")
    source_file="day${day_padded}/part${part}.cpp"
    executable="day${day_padded}/solution${part}"
    input_file="day${day_padded}/input.txt"

    if [ ! -f "$source_file" ]; then
        echo "${RED}Error: Source file $source_file not found${RESET}"
        return 1
    fi

    if [ ! -f "$input_file" ]; then
        echo "${RED}Error: Input file $input_file not found${RESET}"
        return 1
    fi

    echo "${BLUE}Compiling $source_file...${RESET}"
    clang++ -std=c++23 -O2 -fsanitize=address -Wall -Wextra -Wpedantic "$source_file" -o "$executable"

    if [ $? -eq 0 ]; then
        echo "${GREEN}Compilation successful${RESET}"
        echo "${BLUE}Running solution...${RESET}"
        echo "${BOLD}Output:${RESET}"
        echo "----------------------------------------"
        ASAN_OPTIONS=detect_leaks=0 "$executable" <"$input_file"
        result=$?
        echo "----------------------------------------"
        cleanup "$day" "$part"
        return $result
    else
        echo "${RED}Compilation failed${RESET}"
        cleanup "$day" "$part"
        return 1
    fi
}

if [ $# -lt 1 ]; then
    usage
fi

day=$1
part=$2

case $day in
[1-9] | 1[0-9] | 2[0-5]) ;;
*)
    echo "${RED}Error: Day must be between 1 and 25${RESET}"
    exit 1
    ;;
esac

if [ -n "$part" ]; then
    case $part in
    [1-2]) ;;
    *)
        echo "${RED}Error: Part must be either 1 or 2${RESET}"
        exit 1
        ;;
    esac
fi

print_header "$day" "$part"

if [ -n "$part" ]; then
    compile_and_run "$day" "$part"
else
    compile_and_run "$day" "1"
    if [ $? -eq 0 ]; then
        echo
        compile_and_run "$day" "2"
    fi
fi
