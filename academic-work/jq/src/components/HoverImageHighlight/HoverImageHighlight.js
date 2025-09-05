// src/components/HoverImageHighlight.js
import image1 from './images/image1.png';
import image2 from './images/image2.png';
import image3 from './images/image3.png';
import $ from 'jquery';
function HoverImageHighlight() {
    // 图片路径
    // const image1 = image1;
    // const image2 = image2;
    // const image3 = image3;
    // 页面结构动态生成
    // 页面加载结束之后执行callback代码
    $(function () {
        const imageData = [image1, image2, image3];
        const container = $('.hover-image-highlight')
        function generateStructure() {
            // 在页面中动态添加图片
            // NOTE: 为什么这里可以使用foreach 弄清楚对象
            imageData.forEach(url => {
                const imgElement = $('<img>');
                imgElement.attr('src',url);
                imgElement.attr('alt','image');
                container.append(imgElement);
            });
        }
        

        // 交互样式实现
        // 初始化 .hover-image-highlight整体有灰色蒙层
        // 监听鼠标移动 如果进入图片 则挖空对应区域大小的灰色蒙层 将图片显示出来

        // TODO: 前端代码调试报错非常混乱 需要整理一些调试路径才行
        // 找到所有图片 
        function applyInteractions(){
            // 找到所有图片元素
            const images = $('img')
            console.log(images)
            images.each((_,img) => {
                $(img).on('mouseover',function() {
                    console.log('Mouse over event triggered');
                    $(this).addClass('hlight');
                });
    
                $(img).on('mouseout', function() {
                    $(this).removeClass('hlight');
                });
            });
            // images.each((index, element) => {
            //     $(element).on('mouseover', function() {
            //         console.log('Mouse over event triggered');
            //         $(this).addClass('hlight');
            //     });
        
            //     $(element).on('mouseout', function() {
            //         $(this).removeClass('hlight');
            //     });
            // });
        }

        generateStructure();
        applyInteractions();
        
        
    })

}

// 导出函数
export default HoverImageHighlight;
