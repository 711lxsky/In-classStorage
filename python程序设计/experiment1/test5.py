import argparse
import chardet

# 设置 argparse 解析器
parser = argparse.ArgumentParser(description='Convert file to UTF-8 encoding.')
parser.add_argument('filename', type=str, help='The name of the file to convert.')
parser.add_argument('--encoding', type=str, help='The encoding of the input file.', default=None)

# 解析命令行参数
args = parser.parse_args()

# 读取文件内容，并尝试猜测编码格式（如果未提供）
def read_file(filename, encoding=None):
    with open(filename, 'rb') as file:
        raw_data = file.read()
        if encoding is None:
            result = chardet.detect(raw_data)
            encoding = result['encoding']
        return raw_data.decode(encoding)

# 将文件内容写入新文件，使用UTF-8编码
def write_file(filename, content):
    with open(filename, 'w', encoding='utf-8') as file:
        file.write(content)

# 主程序
def main():
    # 读取文件
    try:
        content = read_file(args.filename, args.encoding)
    except Exception as e:
        print(f"Error reading file: {e}")
        return

    # 写入新文件
    try:
        new_filename = f"{args.filename}_utf8.txt"
        write_file(new_filename, content)
        print(f"File converted successfully and saved as {new_filename}")
    except Exception as e:
        print(f"Error writing file: {e}")

if __name__ == "__main__":
    main()
