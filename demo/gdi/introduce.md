# GDI关键知识点

## GDI  
Graphic Device Interface，图形设备接口
## CDC   
设备环境

## GDI和DC关系  
在单任务环境如MS-DOS中，应用程序可以自己的做它想做的事情，无论是在屏幕上画一条线，重新编写适配器的调色板，还是转换到另一种图像模式。而在窗口化多任务环境如Windows中，程序则失去了这种自由，因为程序A的输出必须与程序B的输出格开，首先这意味着各程序的输出必须限制在自己的窗口中。GDI()使用单一的机制保证在窗口中画图的个程序遵循这一规则，这种机制我们称之为设备描述表（或者设备环境）。


当Windows程序在屏幕、打印机或其他输出设备上画图时，它并不是将像素直接输出到设备上，而是将图绘制到由设备描述表（DC）表示的逻辑意义上的"显示平面"上去。设备描述表是Windows内在的一种数据结构，它包含GDI需要的所有关于显示平面情况的描述字段，包括相连的物理设备和各种各样的状态信息。在屏幕上画图之前，Windows程序从GDI获取设备描述表句柄（DeviceContext Handle），每一次调用一个GDI输出函数时它就会把这个句柄传回给GDI。如果没有有效的设备句柄，则GDI不会做任何的绘图动作。通过设备描述表，GDI可确保程序所画的任何图形都能剪贴到屏幕的特定区域。设备描述表在使GDI摆脱设备限制的过程中发挥了重要的作用。获得设备描述表的句柄之后，同一GDI函数可以向多种输出设备上画图。


## DC示例
我们想在重绘的时候始终显示一段欢迎语，就应该在OnDraw函数中添加

	void CTextView::OnDraw(CDC* pDC)
	{
		CTextDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		// TODO: add draw code for native data here

	    // 这是用的第二种方法，我们看到OnDraw的参数正是CDC对象指针
		// pDC->TextOut(200,200,"Lide Only"); //使用的是封装在CDC类中的TextOut，无需给他传递DC
	
		//也无需关心m_hWnd的事情，CDC类内部依旧完成了这项工作
	
		// HDC hdc; //依旧使用老方法获取dc
		// hdc = ::GetDC(m_hWnd);
		// ::TextOut(hdc,400,400,"Lide Only",9); //使用的是全局函数TextOut
	}


GDI是图形设备接口的意思，包括DC,HBITMAP,HFONT,HPEN,HBRUSH等等。

CDC只是用C++把DC给封装了。

CDC就是设备环境，   
**GDI中也包括该元素，正如楼上所说的，用GDI绘图时，先申请设备环境CDC，再在上面用其他工具绘图**

 
GDI是一个windows图形函数库，它的作用类似于tc/dos下的graphics库。
而CDC是这个函数库里定义的一个数据结构，GDI里面的函数需要用到它。
CDC里包含了一些相关联的信息。
比如调色板、画笔、刷子等。


**这么说吧，刷子，笔，调色板GDI放在你面前，你手上有个控制器CDC，可以用来控制这些工具，而不必管刷子是刷鞋CBrush的还是刷衣服的，笔CPen是毛笔还是画笔，只要你按下按钮CDC::DrawXX，它们都能帮你实现
这就是CDC控制GDI的设备无关性**


## 函数收集
- SelectObject
把一个对象(位图、画笔、画刷等)选入指定的设备描述表。新的对象代替同一类型的老对象。
	
		HGDIOBJ SelectObject(
		  HDC hdc,          // handle to DC
		  HGDIOBJ hgdiobj   // handle to object
		);
- BitBlt
该函数对指定的源设备环境区域中的像素进行位块（bit_block）转换，以传送到目标设备环境。

		BOOL BitBlt(
		  HDC hdcDest,
		  int nXDest, int nYDest, int nWidth, int nHeight,
		  HDC hdcSrc,
		  int nXSrc, int nYSrc,
		  DWORD dwRop)；
		
参数：   
hdcDest：指向目标设备环境的句柄。
nXDest、nYDest：指定目标矩形区域左上角的X轴和Y轴逻辑坐标
nWidth、nHeight：指定源和目标矩形区域的逻辑宽度和逻辑高度。
hdcSrc：指向源设备环境的句柄。
nXSrc、nYSrc：指定源矩形区域左上角的X轴和Y轴逻辑坐标。
dwRop：指定光栅操作代码。这些代码将定义源矩形区域的颜色数据，如何与目标矩形区域的颜色数据组合以完成最后的颜色。下面列出了一些常见的光栅操作代码：

值描述
 
	BLACKNESS :表示使用与物理调色板的索引0相关的色彩来填充目标矩形区域，（对缺省的物理调色板而言，该颜色为黑色）。
	DSTINVERT:表示使目标矩形区域颜色取反。
	MERGECOPY :表示使用布尔型AND（与）操作符将源矩形区域的颜色与特定模式组合一起。
	MERGEPAINT :通过使用布尔型OR（或）操作符将源矩形区域的颜色取反后与目标矩形区域的颜色合并。
	NOTSRCCOPY :将源矩形区域颜色取反，拷贝到目标矩形区域。
	NOTSRCERASE :使用布尔类型的OR（或）操作符组合源和目标矩形区域的颜色值，然后将合成的颜色取反。
	PATCOPY :将特定的模式拷贝到目标位图上。
	PATINVERT :通过使用布尔型XOR（异或）操作符将源和目标矩形区域内的颜色合并。	
	PATPAINT :通过使用布尔型OR（或）操作符将源矩形区域取反后的颜色值与特定模式的颜色合并。然后使用OR（或）操作符将该操作的结果与目标矩形区域内的颜色合并。	
	SRCAND :通过使用布尔型AND（与）操作符来将源和目标矩形区域内的颜色合并。	
	SRCCOPY :将源矩形区域直接拷贝到目标矩形区域。	
	SRCERASE :通过使用布尔型AND（与）操作符将目标矩形区域颜色取反后与源矩形区域的颜色值合并。	
	SRCINVERT :通过使用布尔型XOR（异或）操作符将源和目标矩形区域的颜色合并。	
	SRCPAINT :通过使用布尔型OR（或）操作符将源和目标矩形区域的颜色合并。	
	WHITENESS :使用与物理调色板中索引1有关的颜色填充目标矩形区域。（对于缺省物理调色板来说，这个颜色就是白色）。


