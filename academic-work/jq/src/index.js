import $ from 'jquery';
import HoverImageHighlight from './components/HoverImageHighlight';

// 将 jQuery 赋值给全局对象
window.$ = $;
window.jQuery = $;

// 现在可以在其他脚本中使用 $
$(document).ready(function() {
    console.log("jQuery is working!");
});
