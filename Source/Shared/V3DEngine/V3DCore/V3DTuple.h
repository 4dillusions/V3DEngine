/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCore
{
	template <typename T1> class V3DTuple1 final
	{
	public:
		T1 item1;

		V3DTuple1(T1 item1) : item1{ item1 }
		{ }
	};

	template <typename T1, typename T2> class V3DTuple2 final
	{
	public:
		T1 item1;
		T2 item2;

		V3DTuple2(T1 item1, T2 item2) : item1{ item1 }, item2{ item2 }
		{ }
	};

	template <typename T1, typename T2, typename T3> class V3DTuple3 final
	{
	public:
		T1 item1;
		T2 item2;
		T3 item3;

		V3DTuple3(T1 item1, T2 item2, T3 item3) : item1{ item1 }, item2{ item2 }, item3{ item3 }
		{ }
	};

	template <typename T1, typename T2, typename T3, typename T4> class V3DTuple4 final
	{
	public:
		T1 item1;
		T2 item2;
		T3 item3;
		T4 item4;

		V3DTuple4(T1 item1, T2 item2, T3 item3, T4 item4) : item1{ item1 }, item2{ item2 }, item3{ item3 }, item4{ item4 }
		{ }
	};

	template <typename T1, typename T2, typename T3, typename T4, typename T5> class V3DTuple5 final
	{
	public:
		T1 item1;
		T2 item2;
		T3 item3;
		T4 item4;
		T5 item5;

		V3DTuple5(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5) : item1{ item1 }, item2{ item2 }, item3{ item3 }, item4{ item4 }, item5{ item5 }
		{ }
	};

	class V3DTuple final
	{
	public:
		V3DTuple() = delete;
		V3DTuple(const V3DTuple&) = delete;
		V3DTuple(V3DTuple&&) = delete;
		~V3DTuple() = delete;
		V3DTuple& operator=(const V3DTuple&) = delete;
		V3DTuple& operator=(V3DTuple&&) = delete;

		template <typename T1> static V3DTuple1<T1> Create(T1 item1)
		{
			return V3DTuple1<T1>(item1);
		}

		template <typename T1, typename T2> static V3DTuple2<T1, T2> Create(T1 item1, T2 item2)
		{
			return V3DTuple2<T1, T2>(item1, item2);
		}

		template <typename T1, typename T2, typename T3> static V3DTuple3<T1, T2, T3> Create(T1 item1, T2 item2, T3 item3)
		{
			return V3DTuple3<T1, T2, T3>(item1, item2, item3);
		}

		template <typename T1, typename T2, typename T3, typename T4> static V3DTuple4<T1, T2, T3, T4> Create(T1 item1, T2 item2, T3 item3, T4 item4)
		{
			return V3DTuple4<T1, T2, T3, T4>(item1, item2, item3, item4);
		}

		template <typename T1, typename T2, typename T3, typename T4, typename T5> static V3DTuple5<T1, T2, T3, T4, T5> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5)
		{
			return V3DTuple5<T1, T2, T3, T4, T5>(item1, item2, item3, item4, item5);
		}
	};
}
