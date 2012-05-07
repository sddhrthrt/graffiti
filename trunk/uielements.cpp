template <class var> class Trackbar {
	public:
		var* variable;
		float x_pos, y_pos, x_len, y_len;
		float pos;
		float buttonarea[4];
		Trackbar () {};
		~Trackbar () {};
		Trackbar(float x_p, float y_p, var* v, float x_l=2.0f, float y_l=10.0f){
			x_pos=x_p;
			y_pos=y_p;
			variable=v;
			x_len=x_l;
			y_len=y_l;
			pos=0.0f;
			buttonarea[0]=x_pos+x_len/2-0.5f;
			buttonarea[1]=y_pos;
			buttonarea[2]=x_pos+x_len/2+0.5f;
			buttonarea[3]=y_pos+0.5f;
		};
		void move(float x){
			if((buttonarea[1]+x)>y_pos&&buttonarea[3]+x<x_pos+y_len){
				buttonarea[1]-=x;
				buttonarea[3]-=x;
				pos+=x/y_len;
			}
		}
		void draw(){
			Point p1 (x_pos, y_pos);
			Point p2 (x_pos+x_len, y_pos+y_len);
			Rectangle bararea (p1, p2, pallete[6], 1, pallete[1], 0.0f);
			bararea.draw();
			Point p3 (buttonarea[0], buttonarea[1]);
			Point p4 (buttonarea[2], buttonarea[3]);
			Rectangle button (p3, p4, pallete[6], 1, pallete[2], 0.0f);
			button.draw();
		}
};


