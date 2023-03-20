'use strict';

export class Router {
  private static instance: Router;
  public static getInstance(context: any): Router {
    Router.instance = Router.instance || new Router(context);
    return Router.instance;
  }

  public _wasm_router: any = null;

  constructor(context: any) {
    this._wasm_router = new context.module.Router();
  }

  public addRoute(route: string, callback: any): void {
    this._wasm_router.addRoute(route, callback);
  }

  public navigate(fragment: string): void {
    this._wasm_router.navigate(fragment);
  }
};
