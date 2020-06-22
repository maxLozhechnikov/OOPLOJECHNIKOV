#include "pch.h"
#include "CppUnitTest.h"
#include"../HTMLDecoder/HTMLDecoderFunctions.h"
#include"../HTMLDecoder/stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HTMLDecoderTests
{
	TEST_CLASS(HTMLDecoderTests)
	{
	public:
		TEST_METHOD(HTMLDecode_EmptyString_EmptyString)
		{
			std::string result = "";
			auto htmlDecoded = HTMLDecode(result);

			Assert::AreEqual(htmlDecoded, result);
		}

		TEST_METHOD(HTMLDecode_StringWithhoutEntities_SimilarString)
		{
			std::string result = "Withhout entities";
			auto htmlDecoded = HTMLDecode(result);

			Assert::AreEqual(htmlDecoded, result);
		}

		TEST_METHOD(HTMLDecode_StringWithDecodingEntities_DecodedString)
		{
			std::string result = "Love & peace";
			auto htmlDecoded = HTMLDecode("Love &amp; peace");

			Assert::AreEqual(htmlDecoded, result);
		}

		TEST_METHOD(HTMLDecode_Example_DecodedString)
		{
			std::string result = "Cat <says> \"Meow\". M&M's ";
			auto htmlDecoded = HTMLDecode("Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s ");

			Assert::AreEqual(htmlDecoded, result);
		}
	};
}
