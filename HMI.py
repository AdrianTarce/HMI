import tkinter as tk
from PIL import Image, ImageTk

root = tk.Tk()

canvas = tk.Canvas(root, width=430, height=276)
canvas.grid(columnspan=3)

#poza
poza = Image.open("cosmos.jpg")
poza = ImageTk.PhotoImage(poza)
poza_label = tk.Label(image=poza)
poza_label.image = poza
poza_label.grid(columnspan=1,column=1,row=0)

##instructions = tk.Label(root,text="vezi tu pe ce butoane apesi")
##instructions.grid(columnspan=1,column=1,row=0)

next_text = tk.StringVar()
next_btn = tk.Button(root, width=5, textvariable=next_text, font="Raleway")
next_text.set(">>")
next_btn.grid(column=1, row=0)
next_btn.place(x=360, y=230)

slow_text = tk.StringVar()
slow_btn = tk.Button(root, height=2, width=9, textvariable=slow_text, font="Raleway")
slow_text.set("Mai incet")
slow_btn.grid(column=1, row=0)
slow_btn.place(x=130, y=160)

fast_text = tk.StringVar()
fast_btn = tk.Button(root, height=2, width=9, textvariable=fast_text, font="Raleway")
fast_text.set("Mai repede")
fast_btn.grid(column=1, row=0)
fast_btn.place(x=230, y=160)

ON_text = tk.StringVar()
ON_btn = tk.Button(root, height=2, width=9, textvariable=ON_text, font="Raleway")
ON_text.set("PORNIT")
ON_btn.grid(column=1, row=0)
ON_btn.place(x=130, y=220)

OFF_text = tk.StringVar()
OFF_btn = tk.Button(root, height=2, width=9, textvariable=OFF_text, font="Raleway")
OFF_text.set("OPRIT")
OFF_btn.grid(column=1, row=0)
OFF_btn.place(x=230, y=220)

root.mainloop()
