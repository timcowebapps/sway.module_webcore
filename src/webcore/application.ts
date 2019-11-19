"use strict";

export class Application {
	public _wasm_application: any = null;

	constructor(context: any, elementId: string, view: any) {
		this._wasm_application = new context.module.Application(elementId, view._wasm_viewcomponent);
	}
};
