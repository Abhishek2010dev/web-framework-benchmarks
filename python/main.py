# main.py
from fastapi import FastAPI
from fastapi.responses import JSONResponse
import uvicorn

app = FastAPI()


@app.get("/ping")
async def ping():
    return JSONResponse(content={"message": "pong"})


if __name__ == "__main__":
    uvicorn.run("main:app", host="0.0.0.0", port=8080, workers=1)
