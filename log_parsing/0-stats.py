from collections import defaultdict
import re
import sys

""" Read the stdin and compute metrics """


def print_stats(total_size, status_code):
    """Print the status code and file size"""
    print(f"File size: {total_size}")
    for code in sorted(status_code.key()):
        print(f"{code}: {status_code[code]}")


def main():
    """Main function to process the stdin line"""
    counter = 0
    total_size = 0
    status_count = defaultdict(int)
    pattern = re.compile(
        r'^(\S+) - \[(.*?)\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
    )

    try:
        for line in sys.stdin:
            line = line.strip()
            match = pattern.match(line)
            if match:
                status_code = match.group(3)
                file_size = int(match.group(4))

                total_size += file_size
                if status_code in {
                    "200",
                    "301",
                    "400",
                    "401",
                    "403",
                    "404",
                    "405",
                    "500",
                }:
                    status_count[status_code] += 1

            counter += 1
            if counter % 10 == 0:
                print_stats(total_size, status_count)
    except KeyboardInterrupt:
        print_stats(total_size, status_count)
        raise

    print_stats(total_size, status_count)


if __name__ == "__main__":
    main()
