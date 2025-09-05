@echo off
REM 关闭正在运行的 Webpack 开发服务器
echo Stopping Webpack Dev Server if it's running...
taskkill /IM "node.exe" /F

REM 安装依赖项（可选，根据需要注释掉）
echo Installing dependencies...
npm install

REM 启动 Webpack 开发服务器
echo Starting Webpack Dev Server...
npm start

REM 保持命令提示符窗口打开
pause
