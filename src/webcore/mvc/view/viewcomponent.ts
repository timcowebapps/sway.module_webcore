"use strict";

import * as _ from "underscore";
import { IViewComponentOptions } from "./viewcomponentoptions";

export interface IView {
	[name: string]: any;
	_wasm_viewcomponent: any;
};

export class ViewComponent implements IView {
	public _wasm_viewcomponent: any = null;

	/**
	 * Конструктор представления.
	 * 
	 * @method constructor
	 * @param {any} context Контекст.
	 * @param {IViewOptions} options Свойства представления.
	 */
	constructor(context: any, options: IViewComponentOptions) {
		this._wasm_viewcomponent = function (self: any) {
			var ViewComponent = context.module.ViewComponent.extend("ViewComponent", {
				// Empty
			});

			const defaultOptions = { tagname: "div", classname: "" };
			return new ViewComponent(options.id, _.defaults(options, defaultOptions));
		}(this) as any;

		this.initialize(context);
	}

	public initialize(context: any): void {
		// Empty
	}

	public setRegion(region: any): void {
		this._wasm_viewcomponent.setRegion(region);
	}

	public setModel(model: any): void {
		this._wasm_viewcomponent.setModel(model._wasm_model);
	}

	public addChild(view: IView): void {
		this._wasm_viewcomponent.addChild(view._wasm_viewcomponent);
	}

	public addEvent(targetId: string, type: any, callback: any): void {
		this._wasm_viewcomponent.addEvent(targetId, type, callback);
	}
};
