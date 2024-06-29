#!/usr/bin/env python3
"""ChatGPTのOpenAI Python API Library v1.0を使って対話を行う"""
from argparse import ArgumentParser
from os import getenv
from openai import chat


def get_openai_response(prompt: str) -> str:
    """OpenAI APIを使用して応答を取得する関数"""
    response = chat.completions.create(
        model="gpt-3.5-turbo",
        messages=[
            {
                "role": "user",
                "content": prompt,
            }
        ],
        temperature=0.2,
        max_tokens=1000,
    )
    return response.choices[0].message.content


def main():
    """メイン関数"""

    # 環境変数からAPIキーを取得
    api_key = getenv("OPENAI_API_KEY")

    if api_key is None:
        raise ValueError("OPENAI_API_KEYが設定されていません。")

    # ArgumentParserのインスタンスを作成
    parser = ArgumentParser(description="プロンプトを取得します。")

    # コマンドライン引数を定義
    parser.add_argument("prompt", type=str, help="プロンプト")

    # 引数を解析
    args = parser.parse_args()

    # OpenAI APIを使用して応答を取得
    content = get_openai_response(args.prompt)

    # 応答を出力
    print(content)


if __name__ == "__main__":
    main()
