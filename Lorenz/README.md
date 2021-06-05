# Lorenz attractor by UE4 C++ and Niagara
 UE4 C++ とNiagaraを用いてLorenz attractorを可視化しました。
 シミュレーション結果は以下のURLからYoutubeで公開しています。ぜひご覧ください。
 https://youtu.be/BvSOJql9udA
 
 C++を用いてLorenzモデルを4次のRunge-Kutta法で数値計算し、Lorenz attractorを求めました。
 この時、Lorenz attractorを6000点の制御点を持ったSpline曲線で表現しました。
 このSpline曲線上をNiagaraのParticleが沿って移動するようなblueprintを組むことで、動画で表現したような映像を制作しました。
